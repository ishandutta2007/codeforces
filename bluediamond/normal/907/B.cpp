#include <iostream>
using namespace std;
int v[20][20],sol[20][20];
char ch;
int f(char ch)
{
    if(ch=='.')
        return 0;
    if(ch=='x')
        return 1;
    return 2;
}
int r,c;
int rx,cx;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=1;i<=3;i++)
    {
        for(int r=1;r<=3;r++)
        {
            for(int st=1;st<=3;st++)
            {
                ch=cin.get();
                ///cout<<ch<<"\n";
                v[3*(i-1)+r][(st-1)*3+1]=f(ch);
                ch=cin.get();
                ///cout<<ch<<"\n";
                v[3*(i-1)+r][(st-1)*3+2]=f(ch);
                ch=cin.get();
                ///cout<<ch<<"\n";
                v[3*(i-1)+r][(st-1)*3+3]=f(ch);
                ch=cin.get();
            }
        }
        if(i!=3)
            cin.get();
    }
    cin>>r>>c;
    if(r%3==0)rx=3;else rx=r%3;
    if(c%3==0)cx=3;else cx=c%3;
    int rst,rdr,cst,cdr;
    rst=3*(rx-1)+1;
    rdr=3*(rx-1)+3;
    cst=3*(cx-1)+1;
    cdr=3*(cx-1)+3;
    bool ok=0;
    for(int i=rst;i<=rdr;i++)
        for(int j=cst;j<=cdr;j++)
            if(v[i][j]==0)
                ok=1;
    if(ok==1)
            {
            for(int i=rst;i<=rdr;i++)
                for(int j=cst;j<=cdr;j++)
                {
                    if(v[i][j]==0)
                        sol[i][j]=3;
                    else
                        sol[i][j]=v[i][j];
                }
            for(int i=1;i<=9;i++)
                for(int j=1;j<=9;j++)
                {
                    if(rst<=i and i<=rdr and cst<=j and j<=cdr)continue;
                    sol[i][j]=v[i][j];
                }
            }
    if(ok==0)
    {
        for(int i=1;i<=3;i++)
        {
            for(int r=1;r<=3;r++)
            {
                for(int st=1;st<=3;st++)
                {
                    int x=v[3*(i-1)+r][(st-1)*3+1];
                    if(x==0)cout<<"!";else if(x==1)cout<<"x"; else cout<<"o";
                    x=v[3*(i-1)+r][(st-1)*3+2];
                    if(x==0)cout<<"!";else if(x==1)cout<<"x"; else cout<<"o";
                    x=v[3*(i-1)+r][(st-1)*3+3];
                    if(x==0)cout<<"!";else if(x==1)cout<<"x"; else cout<<"o";
                    cout<<" ";
                }
                cout<<"\n";
            }
            cout<<"\n";
        }
        return 0;
    }
    for(int i=1;i<=3;i++)
        {
            for(int r=1;r<=3;r++)
            {
                for(int st=1;st<=3;st++)
                {
                    int x=sol[3*(i-1)+r][(st-1)*3+1];
                    if(x==0)cout<<".";if(x==1)cout<<"x";if(x==2)cout<<"o";if(x==3)cout<<"!";
                    x=sol[3*(i-1)+r][(st-1)*3+2];
                    if(x==0)cout<<".";if(x==1)cout<<"x";if(x==2)cout<<"o";if(x==3)cout<<"!";
                    x=sol[3*(i-1)+r][(st-1)*3+3];
                    if(x==0)cout<<".";if(x==1)cout<<"x";if(x==2)cout<<"o";if(x==3)cout<<"!";
                    cout<<" ";
                }
                cout<<"\n";
            }
            cout<<"\n";
        }
    return 0;
}
/**

rx , cx
 => 3*(rx-1)+1  3*(rx-1)+2  3*(rx-1)+3
 => 3*(cx-1)+1  3*(cx-1)+2  3*(cx-1)+3

**/
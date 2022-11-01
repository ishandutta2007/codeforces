#include<bits/stdc++.h>
using namespace std;

int A[20][20];
int O[20][20];
int X[20][20];
char buf[1000005];
string s;

int sz;
int st[1000005];
int tor[1000005];
int tol[1000005];

int func(int pos){
    if(s[pos]!='('){
        if(s[pos]=='0')return 1;
        if(s[pos]=='1')return 8;
        return 6;
    }
    int l=pos+1;
    int r=((s[l]=='(')?tor[l]+1:l+1)+1;
    int x=func(l);
    int y=func(r);
    char op=s[r-1];
    if(op=='&')return A[x][y];
    if(op=='|')return O[x][y];
    return X[x][y];
}

int parse(){
    int N=s.size();
    int i,j;
    for(i=0;i<N;i++){
        if(s[i]=='('){
            st[sz]=i;
            sz++;
        }else{
            if(s[i]==')'){
                j=st[sz-1];
                sz--;
                tor[j]=i;
                tol[i]=j;
            }
        }
    }
    return func(0);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i,j,x1,x2,y1,y2,z1,z2;

    for(i=0;i<16;i++){
        for(j=0;j<16;j++){
            for(x1=0;x1<2;x1++){
                for(x2=0;x2<2;x2++){
                    for(y1=0;y1<2;y1++){
                        for(y2=0;y2<2;y2++){
                            if(x1==0&&x2==0&&!(i&1))continue;
                            if(x1==0&&x2==1&&!(i&2))continue;
                            if(x1==1&&x2==0&&!(i&4))continue;
                            if(x1==1&&x2==1&&!(i&8))continue;
                            if(y1==0&&y2==0&&!(j&1))continue;
                            if(y1==0&&y2==1&&!(j&2))continue;
                            if(y1==1&&y2==0&&!(j&4))continue;
                            if(y1==1&&y2==1&&!(j&8))continue;
                            z1=(x1&y1);
                            z2=(x2&y2);
                            if(z1==0&&z2==0)A[i][j]|=1;
                            if(z1==0&&z2==1)A[i][j]|=2;
                            if(z1==1&&z2==0)A[i][j]|=4;
                            if(z1==1&&z2==1)A[i][j]|=8;
                            z1=(x1|y1);
                            z2=(x2|y2);
                            if(z1==0&&z2==0)O[i][j]|=1;
                            if(z1==0&&z2==1)O[i][j]|=2;
                            if(z1==1&&z2==0)O[i][j]|=4;
                            if(z1==1&&z2==1)O[i][j]|=8;
                            z1=(x1^y1);
                            z2=(x2^y2);
                            if(z1==0&&z2==0)X[i][j]|=1;
                            if(z1==0&&z2==1)X[i][j]|=2;
                            if(z1==1&&z2==0)X[i][j]|=4;
                            if(z1==1&&z2==1)X[i][j]|=8;
                        }
                    }
                }
            }
        }
    }

    int N;
    cin>>N;
    cin>>buf;
    s=buf;
    int ans=parse();
    if(ans&6){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

    return 0;
}
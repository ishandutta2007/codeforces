#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

//int nr;

int ask(int x,int y)
{
    cout<<"? "<<x<<" "<<y<<endl;
//    if(x%nr>=y%nr) return 1; else return 2;
    string s; cin>>s;
    if(s=="x")
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

int main()
{
  //  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(1)
    {
//        nr++;
        string s;
        cin>>s;
        if(s=="end")
        {
            break;
        }
        int pas=1,r=0;
        while(1)
        {
            int x=ask(pas,2*pas);
          ///  cout<<"kek: "<<pas<<" , "<<2*pas<<"\n";
            if(x==1)
            {
                break;
            }
            else
            {
                pas*=2;
            }
        }
        while(pas)
        {
            int x=ask(r,r+pas);
            if(x==2)
            {
                r+=pas;
            }
            pas/=2;
        }
        r++;
        cout<<"! "<<r<<"\n";
    }
    return 0;
}
/**

**/
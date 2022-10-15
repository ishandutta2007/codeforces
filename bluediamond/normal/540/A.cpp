#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int co[10][10];

int rep(int i)
{
    i%=10; i+=10; i%=10;
    return i;
}

void ask(int i,int j)
{
  //  cout<<i<<" "<<j<<" : "<<co[i][j]<<"\n";
    if(co[i][j]!=-1) return;
    if(i==j)
    {
        co[i][j]=0;
        return;
    }
    ask(rep(i-1),j);
    co[i][j]=1+co[rep(i-1)][j];
    ask(rep(i+1),j);
    co[i][j]=min(co[i][j],1+co[rep(i+1)][j]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i=0;i<10;i++) for(int j=0;j<10;j++) co[i][j]=-1;
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    int res=0;
    for(int i=0;i<n;i++)
    {
        int x=a[i]-'0',y=b[i]-'0';
        ask(x,y);
        res+=co[x][y];
    }
    cout<<res<<"\n";
    return 0;
}
/**


**/
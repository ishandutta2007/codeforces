#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef double lf;
const double EPS=1e-4;
const ll INF=ll(1e18);
const int sINF=int(1e8);
typedef pair<ll,ll> pll;
typedef set<int>::iterator isit;
vector<ll> lager;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    string s;
    cin>>s;
    int p[26];
    memset(p,-1,sizeof p);
    int dis,num;
    for(int i=0;i<27;i++)
    {
        int tmp=s[i]-'A';
        if(p[tmp]==-1)p[tmp]=i;
        else {dis=i-p[tmp]-1;num=p[tmp];break;}
    }
    if(dis==0)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    int st=12-(dis/2);
//    if(dis%2==0)s-=num-1;
//    else s-=num;
    char ans[27];
    memset(ans,0,sizeof ans);
    if(dis%2==0)
    {
        for(int i=0;i<=dis/2;i++)
        {
            ans[st]=s[num+i];
            st++;
        }
        for(int i=12;i>=12-(dis/2)+1;i--)ans[i+13]=s[num+(dis/2)+13-i];
        st=12-(dis/2)-1;
    }
    else
    {
        for(int i=0;i<=dis/2;i++)
        {
            ans[st]=s[num+i];
            st++;
        }
        for(int i=12;i>=12-(dis/2);i--)ans[i+13]=s[num+(dis/2)+13-i];
        st=12-(dis/2)-1;
    }
    num+=dis+2;

    while(1)
    {
        if(num==27)num=0;
        if(st==-1)st=13;
        if(st==26)break;
        if(ans[st]!=0)break;
        ans[st]=s[num];
        num++;
        if(st>=13)st++;
        else st--;
    }
    for(int i=0;i<13;i++)cout<<ans[i];
    cout<<endl;
    for(int i=13;i<26;i++)cout<<ans[i];
    cout<<endl;
}
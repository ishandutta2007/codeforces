#include<bits/stdc++.h>
#define N 200
#define M 500
using namespace std;
int n,m,l[M],p[M],ans;
string s;
int main()
{
    scanf("%d %d",&n,&m);
    s.resize(m,'0');
    for(int i=0;i<m;++i)
    {
        s[i]='1';
        cout<<"? "<<s<<endl;
        cin>>l[i];
        p[i]=i,s[i]='0';
    }
    sort(p,p+m,[&](int a,int b) {return l[a]<l[b];});
    for(int i=0,now;i<m;++i)
    {
        s[p[i]]='1';
        cout<<"? "<<s<<endl;
        cin>>now;
        if(now-ans==l[p[i]]) ans=now;
        else s[p[i]]='0';
    }
    cout<<"! "<<ans<<endl;
    return 0;
}
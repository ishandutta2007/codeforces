#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        auto q=[&](int a,int b,int c)->int
        {
            cout << "? " << a << " " << b << " " << c << endl;
            int x;
            cin >> x;
            if(x==-1) exit(0);
            return x;
        };
        vector<int> v(n/3,-1);
        int one=0,two=0;
        for(int i=0;i<n/3;i++)
        {
            v[i]=q(3*i+1,3*i+2,3*i+3);
            if(v[i]==0) one=i;
            if(v[i]==1) two=i;
        }
        vector<int> r(n+1,-1);
        array<int,3> a={3*one+1,3*one+2,3*one+3};
        array<int,3> b={3*two+1,3*two+2,3*two+3};
        if(q(a[0],a[1],b[0])==0&&q(a[0],a[1],b[1])==0)
        {
            r[a[0]]=r[a[1]]=0;
            r[a[2]]=1-(q(a[0],a[2],b[0])==0&&q(a[0],a[2],b[1])==0);
        }
        else
        {
            r[a[2]]=0;
            r[a[0]]=1-(q(a[0],a[2],b[0])==0&&q(a[0],a[2],b[1])==0);
            r[a[1]]=1-r[a[0]];
        }
        int x=0;
        for(int p:a) if(r[p]==0) x=p;
        if(q(b[0],b[1],x)==1)
        {
            r[b[0]]=r[b[1]]=1;
            r[b[2]]=q(x,b[0],b[2]);
        }
        else
        {
            r[b[2]]=1;
            r[b[0]]=q(x,b[2],b[0]);
            r[b[1]]=1-r[b[0]];
        }
        int y=0;
        for(int p:b) if(r[p]==1) y=p;
        for(int i=0;i<n/3;i++)
        {
            if(i==one||i==two) continue;
            array<int,3> p={3*i+1,3*i+2,3*i+3};
            int z=(v[i]==1?x:y);
            int c=q(p[0],p[1],z);
            int d=q(p[1],p[2],z);
            array<int,3> tmp={v[i],v[i],v[i]};
            if(c!=v[i]&&d==v[i]) tmp[0]=1-v[i];
            else if(c!=v[i]&&d!=v[i]) tmp[1]=1-v[i];
            else if(c==v[i]&&d!=v[i]) tmp[2]=1-v[i];
            for(int j=0;j<3;j++) r[p[j]]=tmp[j];
        }
        vector<int> res;
        for(int i=1;i<=n;i++) if(r[i]==0) res.push_back(i);
        cout << "! " << res.size();
        for(int p:res) cout << " " << p;
        cout << endl;
    }
    return 0;
}
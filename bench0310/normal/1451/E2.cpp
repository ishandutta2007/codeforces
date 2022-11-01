#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int q(int i,int j,string s)
{
    cout << s << " " << i << " " << j << "\n";
    cout.flush();
    int x;
    cin >> x;
    if(x==-1) exit(0);
    return x;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> x(n+1,0);
    for(int i=2;i<=n;i++) x[i]=q(1,i,"XOR");
    vector<array<int,2>> v;
    for(int i=2;i<=n;i++) v.push_back({x[i],i});
    sort(v.begin(),v.end());
    auto solve=[&](int one)
    {
        cout << "! " << one << " ";
        for(int i=2;i<=n;i++) cout << (one^x[i]) << " \n"[i==n];
        cout.flush();
        exit(0);
    };
    for(int i=2;i<=n;i++) if(x[i]==0) solve(q(1,i,"OR"));
    for(int i=0;i<n-2;i++)
    {
        if(v[i][0]==v[i+1][0])
        {
            int y=q(v[i][1],v[i+1][1],"OR");
            solve(y^x[v[i][1]]);
        }
    }
    int j=-1;
    for(int i=2;i<=n;i++) if(x[i]==1) j=i;
    int k=-1;
    for(int i=2;i<=n;i++) if(i!=j&&(x[i]&1)) k=i;
    solve(q(1,j,"AND")+1-(q(j,k,"AND")&1));
    return 0;
}
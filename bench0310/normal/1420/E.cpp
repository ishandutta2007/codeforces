#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct cht
{
    deque<array<int,2>> d;
    bool rm(array<int,2> a,array<int,2> b,array<int,2> c) {return (b[1]-a[1])*(b[0]-c[0])>(c[1]-b[1])*(a[0]-b[0]);}
    void add(int k,int n)
    {
        array<int,2> a={k,n};
        while(d.size()>=2&&rm(d[d.size()-2],d.back(),a)) d.pop_back();
        d.push_back(a);
    }
    int eval(array<int,2> a,int b) {return (a[0]*b+a[1]);}
    int query(int a)
    {
        while(d.size()>=2&&eval(d[0],a)>=eval(d[1],a)) d.pop_front();
        return eval(d[0],a);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    int cnt=0;
    vector<int> pos(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        cnt+=a[i];
        if(a[i]==1) pos[cnt]=i;
    }
    int zero=n-cnt;
    int pairs=n*(n-1)/2;
    if(cnt==0)
    {
        for(int i=0;i<=pairs;i++) cout << "0" << " \n"[i==pairs];
        return 0;
    }
    int dp[n+1][cnt+1][pairs+1];
    cht best[cnt+1][pairs+1];
    for(int i=0;i<=pairs;i++) best[0][i].add(0,0);
    for(int i=1;i<=n;i++)
    {
        for(int c=1;c<=cnt;c++)
        {
            int d=abs(pos[c]-i);
            for(int mv=d;mv<=pairs;mv++)
            {
                dp[i][c][mv]=(i-1)*(i-1)+best[c-1][mv-d].query(i);
                best[c][mv].add(-2*i,i*i+2*i+dp[i][c][mv]);
            }
        }
    }
    vector<int> res(pairs+1,0);
    for(int i=1;i<=n;i++)
    {
        for(int mv=0;mv<=pairs;mv++)
        {
            if(abs(pos[cnt]-i)>mv) continue;
            res[mv]=max(res[mv],zero*(zero-1)/2+(zero-dp[i][cnt][mv]-(n-i)*(n-i))/2);
        }
    }
    for(int i=0;i<=pairs;i++) cout << res[i] << " \n"[i==pairs];
    return 0;
}
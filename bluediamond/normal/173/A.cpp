#include <bits/stdc++.h>

using namespace std;

inline int who(char a,char b)
{
    if(a==b) return 0;
    if(a=='R' && b=='S') return 1;
    if(a=='S' && b=='P') return 1;
    if(a=='P' && b=='R') return 1;
    return 2;
}

int games;

int cnt[3];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>games;
    string a,b; cin>>a>>b;
    int A=games/((a.size())*(b.size()));
    int B=games%((a.size())*(b.size()));
    for(int i=0;i<((a.size())*(b.size()));i++)
        cnt[who(a[i%(a.size())],b[i%(b.size())])]++;
    cnt[1]*=A;
    cnt[2]*=A;
    for(int i=0;i<B;i++)
        cnt[who(a[i%(a.size())],b[i%(b.size())])]++;
    cout<<cnt[2]<<" "<<cnt[1]<<"\n";
    return 0;
}
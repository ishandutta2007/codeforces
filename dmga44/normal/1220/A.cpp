#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int c[5];
    c[0]=c[1]=c[2]=c[3]=c[4]=0;
    string s;
    cin >> s;
    for(int  i=0;i<n;i++)
    {
        if(s[i]=='z')
            c[0]++;
        if(s[i]=='e')
            c[1]++;
        if(s[i]=='r')
            c[2]++;
        if(s[i]=='o')
            c[3]++;
        if(s[i]=='n')
            c[4]++;
    }

    int x=min(c[1],c[3]);
    int ones=min(c[4],x);
    x-=ones;
    int zeroes=min(x,min(c[0],c[2]));
    for(int i=0;i<ones;i++)
        cout << 1 << ' ';
    for(int i=0;i<zeroes;i++)
        cout << 0 << ' ';
    cout << '\n';

    return 0;
}
#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int n=s.size(),a=0;
    for(int i=0;i<n;i++)
        if(s[i]=='a')
            a++;
    db(min(n,a*2-1))

    return 0;
}
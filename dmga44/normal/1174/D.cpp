#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

bool mk[(1<<19)];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,x;
    cin >> n >> x;
    for(int i=0;i<(1<<n);i++)
        if(!mk[i^x])
            mk[i]=1;
    vector<int> pos;
    for(int i=0;i<(1<<n);i++)
        if(mk[i])
            pos.push_back(i);
    db(pos.size()-1)
    for(int i=1;i<pos.size();i++)
        pos[i-1]=pos[i]^pos[i-1];
    for(int i=1;i<pos.size();i++)
        cout << pos[i-1] << ' ';
    cout << '\n';

    return 0;
}
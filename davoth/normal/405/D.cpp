#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    bool m[(int)1e6+1];
    long long a[n],cnt=0;
    vector<long long> b,c;
    fill(m,m+(int)1e6+1,false);
    for(int i=0; i<n; i++){
        cin >> a[i];
        m[a[i]]=1;
    }
    for(int i=1; i<=5e5; i++){
        if(!m[i] && !m[(int)1e6+1-i]){
            c.push_back(i);
            c.push_back(1e6+1-i);
        }else if(m[i] && m[(int)1e6+1-i]) cnt++;
        else if(m[i]) b.push_back(1e6+1-i);
        else if(m[(int)1e6+1-i]) b.push_back(i);
    }
    for(int i=0; i<cnt; i++){
        b.push_back(c[i*2]);
        b.push_back(c[i*2+1]);
    }
    cout << b.size() << '\n';
    for(int i=0; i<b.size(); i++) cout << b[i] << ' ';
    return 0;
}
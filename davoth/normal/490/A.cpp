#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,a=0,b=0,c=0;
    cin >> n;
    int d[n];
    vector<int> e,f,g;
    for(int i=0; i<n; i++){
        cin >> d[i];
        if(d[i]==1){
            a++;
            e.push_back(i+1);
        }
        else if(d[i]==2){
            b++;
            f.push_back(i+1);
        }
        else{
            c++;
            g.push_back(i+1);
        }
    }
    if(!min(min(a,b),c)){
        cout << 0;
        return 0;
    }
    cout << min(min(a,b),c) << '\n';
    for(int i=0; i<min(min(a,b),c); i++){
        cout << e[i] << ' ' << f[i] << ' ' << g[i] << '\n';
    }
    return 0;
}
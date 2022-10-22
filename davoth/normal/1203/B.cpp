#include <bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin >> q;
    for(int i=0; i<q; i++){
        long long n,cnt=0;
        cin >> n;
        vector<long long> v;
        long long a[10002];
        fill(a,a+10002,0);
        for(int j=0; j<n*4; j++){
            int t;
            cin >> t;
            a[t]++;
            cnt++;
            if(a[t]%2==0 && a[t]!=0){
                cnt-=2;
                v.push_back(t);
            }
        }
        int c=0;
        if(cnt != 0){
            cout << "NO\n";
            c=1;
            continue;
        }
        if(v.size()%2==1 && c==0){
            cout << "NO\n";
            c=1;
            continue;
        }
        sort(v.begin(),v.end());
        long long area=v[0]*v[v.size()-1];
        if(c==0){
            for(int j=0; j<v.size()/2; j++){
                if(v[j]*v[v.size()-j-1]!=area){
                    cout << "NO\n";
                    c=1;
                    break;
                }
            }
        }
        if(c==0) cout << "YES\n";
    }
    return 0;
}
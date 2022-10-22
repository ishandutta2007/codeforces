#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    string s;
    for(int i=0; i<t; i++) {
        int n,k;
        vector<int> l;
        cin >> n >> k;
        int a[n];
        for(int j=0; j<n; j++){
            cin >> a[j];
            if(a[j]%2==1) l.push_back(j);
        }
        if(l.size()>=k && (l.size()-k)%2==0){
            s+="YES\n";
            for(int j=0; j<k-1; j++){
                s+=to_string(l[j]+1);
                s+=' ';
            }
            s+=to_string(n);
            s+='\n';
        }else{
            s+="NO\n";
        }

    }
    cout << s;
    return 0;
}
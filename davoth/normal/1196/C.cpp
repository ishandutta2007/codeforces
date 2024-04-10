#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    string s;
    for(int i=0; i<t; i++) {
        int max=100000,may=100000,mix=-100000,miy=-100000;
        int n;
        cin >> n;
        int x[n],y[n],f1[n],f2[n],f3[n],f4[n];
        for(int j=0; j<n ;j++){
            cin >> x[j] >> y[j] >> f1[j] >> f2[j] >> f3[j] >> f4[j];
        }
        for(int j=0; j<n; j++){
            if(f1[j]==0 && x[j]>mix){
                mix=x[j];
            }
            if(f2[j]==0 && y[j]<may){
                may=y[j];
            }
            if(f3[j]==0 && x[j]<max){
                max=x[j];
            }
            if(f4[j]==0 && y[j]>miy){
                miy=y[j];
            }
        }
        if(mix<=max && miy<=may){
            s+="1 ";
            s+=to_string(mix);
            s+=" ";
            s+=to_string(miy);
            s+='\n';
        }
        else s+="0\n";
    }
    cout << s;
    return 0;
}
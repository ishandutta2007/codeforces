#include <bits/stdc++.h>
using namespace std;
int main(){
    /*int q;
    cin >> q;
    string s;
    for(int i=0; i<q; i++){
        int n;
        cin >> n;
        vector<int> v;
        int a[10002];
        fill(a,a+10002,0);
        for(int j=0; j<n*4; j++){
            int t;
            cin >> t;
            a[t]++;
            if(a[t]%2==0 && a[t]!=0) v.push_back(t);
        }
        int c=0;
        if((int)v.size()%2==1){
            s+="NO\n";
            c=1;
            continue;
        }
        sort(v.begin(),v.end());
        int area=v[0]*v[v.size()-1];
        if(c==0){
            for(int j=0; j<(int)v.size()/2; j++){
                if(v[j]*v[v.size()-j-1]!=area){
                    s+="NO\n";
                    c=1;
                    break;
                }
            }
        }
        if(c==0) s+="YES\n";
    }
    cout << s;*/
    int n;
    cin >> n;
    int a[150003];
    int b[n];
    fill(a,a+150003,0);
    for(int i=0; i<n; i++){
        cin >> b[i];
    }
    int cnt=0;
    sort(b,b+n);
    for(int i=n-1; i>=0; i--){
        if(a[b[i]+1]==0){
            a[b[i]+1]=1;
            cnt++;
        }else if(a[b[i]]==0){
            a[b[i]]=1;
            cnt++;
        }else if(a[b[i]-1]==0 && b[i]-1>0){
            a[b[i]-1]=1;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
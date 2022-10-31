//https://codeforces.com/problemset/problem/1238/D

#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n; cin >> n;
    string s; cin >> s;
    long long ans = 0;
    long long num[2] = {0};
    long long j = 0;
    for(long long i = 0; i<n; i++){
        if(i != 0) num[s[i-1]-'A']--;
        while(num[0] < 2 || num[1] < 2){
            if(j >= n){
                j = n+1; break;
            }
            num[s[j]-'A']++;
            j++;
        }
        ans += n-j+1;
    }
    long long nu = 0;
    char cur = s[0];
    vector<long long> v;
    for(long long i = 0; i<n; i++){
        if(s[i] == cur) nu++;
        else{
            v.push_back(nu);
            ans += nu*(nu-1)/2;
            nu = 1;
            cur = s[i];
        }
    }
    ans += nu*(nu-1)/2;
    v.push_back(nu);
    for(long long i = 1; i<v.size()-1; i++){
        if(v[i] == 1) ans += v[i-1]*v[i+1];
    }
    cout << ans << endl;
}
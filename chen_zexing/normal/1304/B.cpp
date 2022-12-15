#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#define hash hassh
using namespace std;
string s[105];
int f[105],m;
int check(string a,string b){
    for(int i=0;i<m;i++)
        if(a[i]!=b[m-i-1])
            return 0;
    return 1;
}
int check2(string a){
    for(int i=0;i<m;i++)
        if(a[i]!=a[m-i-1])
            return 0;
    return 1;
}
vector <int> v,v2;
int main() {
    int n;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i],f[i]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
        {
            if(i!=j&&check(s[i],s[j])&&f[i]&&f[j]){
                v.push_back(i);
                f[i]=f[j]=0;
            }
        }
    }
    for(int i=1;i<=n;i++) {
        if (check2(s[i]) && f[i]) {
            v2.push_back(i);
            break;
        }
    }
    cout<<(v.size()*2+v2.size())*m<<endl;
    for(int i=0;i<v.size();i++) cout<<s[v[i]];
    for(int i=0;i<v2.size();i++) cout<<s[v2[i]];
    for(int i=v.size()-1;i>=0;i--){
        for(int j=m-1;j>=0;j--) cout<<s[v[i]][j];
    }
    cout<<endl;
    return 0;
}
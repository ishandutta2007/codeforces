#include <stdio.h>
#include<iostream>
#include<string>
#include <algorithm>
#include <string.h>
#include <vector>
#include <cmath>
#include <map>
#include <unordered_map>
#include <climits>
#include <queue>
using namespace std;
int a[55],b[55],n;
vector <vector<int>> v;
int check(){
    for(int i=1;i<=n;i++) if(a[i]!=i) return 0;
    return 1;
}
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    while(!check()){
        vector <int> v0;
        v0.clear();
        int f=0;
        for(int i=1;i<=n&&f==0;i++)
            for(int j=i+1;j<=n&&f==0;j++){
                if(a[i]==a[j]+1){
                    f=1;
                    if(i-1) v0.push_back(i-1);
                    int k=i;
                    while(a[k+1]==a[k]+1) k++;
                    v0.push_back(k-i+1);
                    v0.push_back(j-k);
                    if(n-j) v0.push_back(n-j);
                    vector <int> t;
                    t.clear();
                    for(int p=j+1;p<=n;p++) t.push_back(a[p]);
                    for(int p=k+1;p<=j;p++) t.push_back(a[p]);
                    for(int p=i;p<=k;p++) t.push_back(a[p]);
                    for(int p=1;p<i;p++) t.push_back(a[p]);
                    for(int k=1;k<=n;k++) a[k]=t[k-1];
                    v.push_back(v0);
                }
            }
    }
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++) {
        cout<<v[i].size()<<" ";
        for (int j = 0; j < v[i].size(); j++) cout<<v[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
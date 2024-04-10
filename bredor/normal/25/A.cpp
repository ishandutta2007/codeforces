//  228

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <bits/stdc++.h>
using namespace std;
 unordered_map<int, int> mp;
int countFreq(int arr[], int n)
{

    for (int i = 0; i < n; i++)
        mp[arr[i]]++;
    for (auto x : mp)
        if(x.second==1) return x.first;
return -1;
}


int main() {
int n;
cin>>n;
int b[n];
int a[n];
for(int i=0;i<n;i++)
{cin>>b[i]; a[i]=b[i]%2;}
if(countFreq(a,n)==0)
{
    for(int i=0;i<n;i++)
    if(b[i]%2==0) {cout<<i+1; break;}
}
else
    for(int i=0;i<n;i++)
    if(b[i]%2==1) {cout<<i+1; break;}

}
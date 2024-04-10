#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
using namespace std;
int a[55];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int cnt1=0,cnt2=0;
        for(int i=1;i<=n;i++) cnt1+=1-a[i];
        for(int i=1;!a[i];i++) cnt2++;
        for(int i=n;!a[i];i--) cnt2++;
        cout<<cnt1-cnt2<<endl;
    }
    return 0;
}
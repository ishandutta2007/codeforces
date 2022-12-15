#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;
int a[505],b[505];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        int f1=0,f2=0,f3=1;
        for(int i=1;i<=n;i++){
            if(b[i]) f1=1;
            else f2=1;
        }
        for(int i=1;i<n;i++) if(a[i]>a[i+1]) f3=0;
        if(f1&&f2||f3) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
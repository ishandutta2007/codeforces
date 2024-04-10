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
#include <unordered_set>
#define hash hassh
using namespace std;
int f[2000],b[2000];
int main() {
    int T=1;
    //cin>>T;
    while(T--) {
        int n,k;
        cin>>n>>k;
        int ans=n;
        for(int i=1;i<=n;i++){
            printf("? %d\n",i);
            fflush(stdout);
            char t='.';
            while(t!='Y'&&t!='N') scanf("%c",&t);
            if(t=='Y') f[i]=1,ans--;
            //cout<<'#';
        }
        int bl=max(1,k/2);
        for(int i=1;i<=n;i++) b[i]=(i-1)/bl+1;
        int m=n/bl;
        for(int i=1;i<m;i++)
            for(int j=i+2;j<=m;j++){
                puts("R");
                fflush(stdout);
                for(int l=(i-1)*bl+1;l<=i*bl;l++) {
                    printf("? %d\n", l), fflush(stdout);
                    char c='.';
                    while(c!='N'&&c!='Y') scanf("%c", &c);
                }
                for(int l=(j-1)*bl+1;l<=j*bl;l++) {
                    printf("? %d\n", l), fflush(stdout);
                    char c='.';
                    while(c!='N'&&c!='Y') scanf("%c", &c);
                    if(c=='Y'&&!f[l]) f[l]=1,ans--;
                }
            }
        printf("! %d\n",ans);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
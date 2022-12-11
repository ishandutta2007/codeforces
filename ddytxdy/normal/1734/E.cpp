#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define mp make_pair
#define pb push_back
#define LL long long
#define pii pair<int,int>
using namespace std;
const int N=400;
int n,a[N][N];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i][i]);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++)
            a[i][j]=(a[i][j-1]+i)%n;
        for(int j=i-1;~j;j--)
            a[i][j]=(a[i][j+1]+n-i)%n;
    }
    for(int i=0;i<n;i++,puts(""))
        for(int j=0;j<n;j++)
            printf("%d ",a[i][j]);
}
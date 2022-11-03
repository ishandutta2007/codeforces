#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>

using namespace std;

int a[101][101];
int rows[101],cols[101];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m;
    cin >> n >> m;
    int sumr[101]={0},sumc[101]={0};
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j) {
            cin >> a[i][j];
            sumr[i]+=a[i][j];
            sumc[j]+=a[i][j];
        }
    vector <int> pr,pc;
    for(int i=0;i<n;++i)
        pr.push_back(i);
    for(int j=0;j<m;++j)
        pc.push_back(j);
    random_shuffle(pr.begin(),pr.end());
    random_shuffle(pc.begin(),pc.end());
    while(true) {
        int row=-1;
        for(int i=0;i<n;++i)
            if (sumr[pr[i]]<0) {
                row=pr[i];
                break;
            }
        if (row!=-1) {
            rows[row]^=1;
            for(int j=0;j<m;++j) {
                sumr[row]-=2*a[row][j];
                sumc[j]-=2*a[row][j];
                a[row][j]*=-1;
            }
            continue;
        }
        int col=-1;
        for(int j=0;j<m;++j)
            if (sumc[pc[j]]<0) {
                col=pc[j];
                break;
            }
        if (col!=-1) {
            cols[col]^=1;
            for(int i=0;i<n;++i) {
                sumc[col]-=2*a[i][col];
                sumr[i]-=2*a[i][col];
                a[i][col]*=-1;
            }
            continue;
        }
        break;
    }
    int cnt=0;
    for(int i=0;i<n;++i)
        cnt+=rows[i];
    printf("%d",cnt);
    for(int i=0;i<n;++i)
        if (rows[i]) printf(" %d",i+1);
    printf("\n");
    cnt=0;
    for(int i=0;i<m;++i)
        cnt+=cols[i];
    printf("%d",cnt);
    for(int i=0;i<m;++i)
        if (cols[i]) printf(" %d",i+1);
    printf("\n");
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
 
int nth_bit(int num, int n){
    return (num >> n) & 1;
}
 
void solve(){
    vector<vector<int>> cp(2, vector<int>(3));
    for(int i=0; i<2; i++) for(int k=2; k>=0; k--) scanf("%d", &cp[i][k]);
    int num[8];
    for(int i=7; i>0; i--) scanf("%d", &num[i]);
 
    int dec[2][3], Dec[3];
    Dec[0] = num[3]+num[5];
    Dec[1] = num[3]+num[6];
    Dec[2] = num[5]+num[6];
    for(int n6=0; n6<=num[6]; n6++) for(int n5=0; n5<=num[5]; n5++) for(int n3=0; n3<=num[3]; n3++){
        dec[0][0] = n3 + n5;
        dec[0][1] = n3 + n6;
        dec[0][2] = n5 + n6;
        dec[1][0] = Dec[0] - dec[0][0];
        dec[1][1] = Dec[1] - dec[0][1];
        dec[1][2] = Dec[2] - dec[0][2];
        int mn0 = min({cp[0][0] - dec[0][0], cp[0][1] - dec[0][1], cp[0][2] - dec[0][2]});
        int mn1 = min({cp[1][0] - dec[1][0], cp[1][1] - dec[1][1], cp[1][2] - dec[1][2]});
        bool ok = (mn0 >= 0 && mn1 >= 0 && mn0 + mn1 >= num[7]);
        for(int k=0; k<3; k++) if(cp[0][k] + cp[1][k] - Dec[k] - num[7] < num[1<<k]) ok = false;
        if(!ok){
            continue;
        }
        int n7 = min(num[7], mn0);
        int n1 = min(num[1], cp[0][0] - dec[0][0] - n7);
        int n2 = min(num[2], cp[0][1] - dec[0][1] - n7);
        int n4 = min(num[4], cp[0][2] - dec[0][2] - n7);
        printf("%d %d %d %d %d %d %d\n", n7, n6, n5, n4, n3, n2, n1);
        return;
    }
    printf("-1\n");
}
 
int main(){
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
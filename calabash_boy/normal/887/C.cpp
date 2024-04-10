#include<bits/stdc++.h>
using namespace std;
const int maxn = 100;
int a[maxn];
bool same[maxn];
int T;
void input(){
    for (int i=0;i<12;i++){
        scanf("%d",a+i);
    }
    scanf("%d%d%d%d",a+17,a+19,a+16,a+18);
    scanf("%d%d%d%d",a+22,a+20,a+23,a+21);
    scanf("%d%d%d%d",a+15,a+14,a+13,a+12);
    
}
bool  solve(){
    memset(same,0,sizeof same);
    for (int i=0;i<6;i++){
        bool ok = true;
        int flag = a[i*4];
        for (int j = i*4+1;j<i*4+4;j++){
            if (a[j]!=flag){
                ok = false;
                break;
            }
        }
        if (ok){
            same[i] = true;
        }
    }
    if (same[0]&&same[1]&&same[2]&&same[3]&&same[4]&&same[5]){
        return false;
    }
    if (same[0]&&same[2]){
        if (a[17]==a[19]&&a[6]==a[7]&&a[16]==a[18]&&a[4]==a[5]&&a[20]==a[22]&&a[21]==a[23]&&a[14]==a[15]&&a[12]==a[13]){
            if (a[17]==a[6]&&a[4]==a[21]&&a[20]==a[12]&&a[14]==a[16]){
                return true;
            }
            if (a[17]==a[12]&&a[4]==a[16]&&a[20]==a[6]&&a[14]==a[21]){
                return true;
            }
        }
    }
    if (same[1]&&same[3]){
        if (a[10]==a[11]&&a[8]==a[9]&&a[0]==a[1]&&a[2]==a[3]&&a[18]==a[19]&&a[16]==a[17]&&a[22]==a[23]&&a[20]==a[21]){
            if (a[10]==a[23]&&a[21]==a[3]&&a[1]==a[19]&&a[17]==a[8]){
                return true;
            }
            if (a[10]==a[19]&&a[21]==a[8]&&a[1]==a[22]&&a[17]==a[2]){
                return true;
            }
        }
    }
    if (same[4]&&same[5]){
        if (a[0]==a[2]&&a[1]==a[3]&&a[4]==a[6]&&a[5]==a[7]&&a[8]==a[10]&&a[9]==a[11]&&a[12]==a[14]&&a[13]==a[15]){
            if (a[0]==a[5]&&a[4]==a[9]&&a[8]==a[13]&&a[12]==a[1]){
                return true;
            }
            if (a[0]==a[13]&&a[4]==a[1]&&a[8]==a[5]&&a[12]==a[9]){
                return true;
            }
        }
    }
    return false;
}
int main(){
	T=1;
    while (T--){
        input();
        if (solve()){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
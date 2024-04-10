#include<bits/stdc++.h>
using namespace std;
const int maxn = 1001110;
int a[maxn];
int n, x, sum = 0;
void input(){
	scanf("%d%d",&n, &x);
}
void init(){
	for(int i = 1; i < n; i ++){
        a[i] = 1;
        sum ^= i;
    }	
}
void solve(){
	if(n == 2 && x == 0){
		puts("NO");
		return ;
	}
    else{
        int tem = x ^ sum;
        if(tem >= n  || !tem)
            a[tem] = 1;
        else{
            for(int i = 1; i < n; i ++){
                if(a[i] && i != tem){
                    a[i] = 0;
                    a[i+(1<<19)] = 1;
                    a[tem+(1<<19)] = 1;
                    break;
                }
            }
        }
        printf("YES\n");
        int check = 0;
        for(int i = 0; i < maxn; i ++)
            if(a[i]){
            check ^= i;
            printf("%d ",i);
        }
    }

}
int main(){
	input();
	init();
    solve();
    return 0;
}
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int ad[1000000]={0}, res[200010], sz=1;
int a, b;
void pl(int l, int r, int o){
    int m = (l+r)>>1;
    if(a<=l && r<=b){
        ad[o]++;
    }
    else{
        if(a <= m) pl(l, m, o*2);
        if(b > m)  pl(m+1, r, o*2+1);
    }
}
void push_down(int o, int l, int r){
    if(l!=r){
        int m = (l+r)>>1;
        ad[o*2] += ad[o];
        ad[o*2+1] += ad[o];
        ad[o] = 0;
        push_down(o*2, l, m);
        push_down(o*2+1, m+1, r);
    }
    else res[sz++] = ad[o];
}

int arr[200010];
int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &arr[i]);
    for(int i = 0; i < q; ++i){
        scanf("%d%d", &a, &b);
        pl(1, n, 1);
    }
    push_down(1, 1, n);

    sort(res+1, res+n+1); sort(arr+1, arr+n+1);


    long long int ans = 0;
    for(int i = 1; i <= n; ++i){
        ans += (long long)res[i] * (long long)arr[i];
    }
    cout << ans << endl;
    return 0;   
}
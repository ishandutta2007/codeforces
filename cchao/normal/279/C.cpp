#include <cstdio>
#define M 100010
int arr[M], inc[M]={0}, dec[M]={0};
int bs(int l, int r){
    int x = l, last = -1;
    int mid = (l + r) / 2;
    while(l <= r){
        mid = (l+r)/2;
        if(inc[mid] - inc[x] == mid - x){last = mid, l = mid+1;}
        else r = mid-1;
    }
    return last;
}
int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &arr[i]);
        if(i && arr[i] >= arr[i-1]) inc[i] = inc[i-1] + 1;
        else if(i) inc[i] = inc[i-1];

        if(i && arr[i] <= arr[i-1]) dec[i] = dec[i-1] + 1;
        else if(i) dec[i] = dec[i-1];
    }

    for(int i = 0; i < q; ++i){
        int l, r; scanf("%d%d", &l, &r);
        int t = bs(l, r);
        if(dec[r] - dec[t] == r-t) puts("Yes");
        else puts("No");
    }
    return 0;
}
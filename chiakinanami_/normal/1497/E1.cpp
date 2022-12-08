#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
int n;
int arr[200002];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &arr[0]);
        for(int i=1; i<=n; i++){
            scanf("%d", &arr[i]);
            for(int j=2; j*j<=arr[i]; j++){
                while(arr[i] % (j*j) == 0){
                    arr[i] /= j*j;
                }
            }
        }

        set<int> st;
        int ans = 1;
        for(int i=1; i<=n; i++){
            if(st.find(arr[i]) != st.end()){
                ans++;
                st.clear();
            }
            st.insert(arr[i]);
        }
        printf("%d\n", ans);
    }
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
int n;
int arr[200002];
set<int> st;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i=1; i<=n; i++) scanf("%d", &arr[i]);

        for(int i=1; i<=n; i++) st.insert(i);
        for(int i=1; i<=n; i++){
            if(arr[i] != arr[i-1]) printf("%d ", arr[i]), st.erase(arr[i]);
            else printf("%d ", *st.begin()), st.erase(st.begin());
        }
        puts("");

        for(int i=1; i<=n; i++) st.insert(i);
        for(int i=1; i<=n; i++){
            if(arr[i] != arr[i-1]) printf("%d ", arr[i]), st.erase(arr[i]);
            else{
                auto it = prev(st.lower_bound(arr[i]));
                printf("%d ", *it);
                st.erase(it);
            }
        }
        puts("");
    }
}
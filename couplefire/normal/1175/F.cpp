#include<bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
#define N 300005

int ap[N];
int E[N];
int a[N];
int big[N][2];
int n;
vector<int> ord[N];
vector<int> st;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    a[0] = n + 1;
    a[n + 1] = n + 1;
    st.push_back(n + 1);


    for(int i = 1; i <= n; i++){
        cin>>a[i];
        ord[a[i]].push_back(i);
        E[i] = max(E[i - 1], ap[a[i]]);

        while(st.back() < a[i]) st.pop_back();
        big[i][0] = ap[st.back()];
        st.push_back(a[i]);

        ap[a[i]] = i;
    }

    st.clear();
    st.push_back(n + 1);
    ap[n + 1] = n + 1;
    for(int i = n; i >= 1; i--){
        while(st.back() < a[i]) st.pop_back();
        big[i][1] = ap[st.back()];
        st.push_back(a[i]);
        ap[a[i]] = i;
    }
    int res= 0;

    for(int i = 1; i <= n; i++){
        for(int x : ord[i]){
            int l = max(x - a[x] + 1, big[x][0] + 1);
            int r = min(x, big[x][1] - a[x]);
            for(int j = l; j <= r; j++){
                res += E[j + a[x] -1] < j;
            }
        }
    }
    cout<<res;
}
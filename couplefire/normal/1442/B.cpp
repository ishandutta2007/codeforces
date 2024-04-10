#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353

struct Node{
    int prev, next;
    Node(){}
};

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int pos[n];
        int arr[n];
        int brr[k];
        bool need[n];
        fill(need, need+n, false);
        for(int i = 0; i<n; i++){
            cin >> arr[i];
            --arr[i];
            pos[arr[i]] = i;
        }
        for(int i = 0; i<k; i++){
            cin >> brr[i];
            --brr[i];
            need[pos[brr[i]]] = 1;
        }
        int ans = 1;
        Node ns[n];
        ns[0].prev = MOD;
        ns[n-1].next = MOD;
        for(int i = 0; i<n-1; i++) ns[i].next = i+1;
        for(int i = 1; i<n; i++) ns[i].prev = i-1;
        for(int i = 0; i<k; i++){
            int p = pos[brr[i]];
            int num = 2;
            if(ns[p].prev == MOD || need[ns[p].prev]) num--;
            if(ns[p].next == MOD || need[ns[p].next]) num--;
            if(num == 0){
                ans = 0;
                break;
            }
            need[p] = 0;
            if(ns[p].prev == MOD || need[ns[p].prev]){
                int l = ns[p].next;
                ns[p].next = ns[ns[p].next].next;
                if(ns[p].next != MOD) ns[ns[p].next].prev = p;
                ns[l].next = MOD;
                ns[l].prev = MOD;
            }
            else{
                int l = ns[p].prev;
                ns[p].prev = ns[l].prev;
                if(ns[p].prev != MOD) ns[ns[p].prev].next = p;
                ns[l].prev = MOD;
                ns[l].next = MOD;
            }
            ans *= num;
            if(ans >= MOD) ans -= MOD;
        }
        cout << ans << endl;
    }
}
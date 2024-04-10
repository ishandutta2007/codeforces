#include <bits/stdc++.h>
using namespace std;

long long get(long long a, long long b, long long c){
    return (a-b)*(a-b)+(a-c)*(a-c)+(b-c)*(b-c);
}

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long t; cin >> t;
    while(t--){
        long long nr, ng, nb; cin >> nr >> ng >> nb;
        vector<long long> arr[3];
        arr[0] = vector<long long>(nr);
        arr[1] = vector<long long>(ng);
        arr[2] = vector<long long>(nb);
        for(long long i = 0; i<nr; i++) cin >> arr[0][i];
        for(long long i = 0; i<ng; i++) cin >> arr[1][i];
        for(long long i = 0; i<nb; i++) cin >> arr[2][i];
        sort(arr[0].begin(), arr[0].end());
        sort(arr[1].begin(), arr[1].end());
        sort(arr[2].begin(), arr[2].end());
        sort(arr, arr+3);
        long long bestans = get(arr[0][0], arr[1][0], arr[2][0]);
        do{
            long long a, b;
            a = b = 0;
            while(a<arr[0].size()){
                long long next;
                if(a == arr[0].size()-1) next = 1000000003;
                else next = arr[0][a+1];
                while(b < arr[1].size() && arr[1][b] < next){
                    long long best = lower_bound(arr[2].begin(), arr[2].end(), arr[1][b])-arr[2].begin();
                    if(best == arr[2].size()) best--;
                    bestans = min(bestans, get(arr[0][a], arr[1][b], arr[2][best]));
                    b++;
                }
                a++;
            }
        } while(next_permutation(arr, arr+3));
        cout << bestans << endl;
    }
}
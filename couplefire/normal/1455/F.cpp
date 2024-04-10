#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 600;
char s[maxn];
int a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    for(cin >> t; t; t -= 1){
        int n, k;
        cin >> n >> k >> s;
        for(int i = 0; i < n; i += 1) a[i] = s[i] - 'a';
        for(int i = 0, p = 0; i < n; i += 1){
            if(p){
                int fm = a[i];
                if(i == n - 1) break;
                int sm = a[i + 1];
                if(i == n - 2){
                    if(fm <= sm){
                        p = 0;
                        continue;
                    }
                    swap(a[i], a[i + 1]);
                    break;
                }
                int tm = a[i + 2];
                if(fm <= sm and fm <= tm){
                    p = 0;
                    continue;
                }
                if(sm <= tm){
                    swap(a[i], a[i + 1]);
                    continue;
                }
                a[i] = tm;
                a[i + 2] = sm;
                a[i + 1] = fm;
                i += 1;
                continue;
            }
            else{
                int fm = min({a[i], (a[i] + k - 1) % k, (a[i] + 1) % k});
                if(i == n - 1){
                    a[i] = fm;
                    break;
                }
                int sm = min({a[i + 1], (a[i + 1] + k - 1) % k, (a[i + 1] + 1) % k});
                if(i == n - 2){
                    if(fm <= sm){
                        a[i] = fm;
                        continue;
                    }
                    if(a[i + 1] == sm){
                        a[i] = sm;
                        a[i + 1] = fm;
                        break;
                    }
                    a[i + 1] = a[i];
                    a[i] = sm;
                    break;
                }
                int tm = a[i + 2];
                if(fm <= sm and fm <= tm){
                    a[i] = fm;
                    continue;
                }
                if(sm <= tm){
                    if(a[i + 1] == sm){
                        a[i] = sm;
                        a[i + 1] = fm;
                        p = 1;
                        continue;
                    }
                    a[i + 1] = a[i];
                    a[i] = sm;
                    p = 1;
                    continue;
                }
                a[i] = tm;
                a[i + 2] = a[i + 1];
                a[i + 1] = fm;
                p = 1;
                i += 1;
            }
        }
        for(int i = 0; i < n; i += 1) cout << char(a[i] + 'a');
        cout << "\n";
    }
    return 0;
}
#include "bits/stdc++.h"

using namespace std;

int n, k;
string str;
int p[500100];
int idx;
string ans;

int main(){
    while(~scanf("%d%d",&n,&k)){
        cin >> str;
        string str_t = str;

        int m = n;
        while(m<k){
            str += str_t;
            m += n;
        }
        n = m;

        p[0] = -1;
        idx = k;
        char c;
        for(int i=1;i<n;i++){
            int j = p[i-1];
            if(str[j+1]< str[i]){
                idx = i - j - 1;
                break;
            }

            while(j!=-1){
                if(str[j+1]==str[i]) break;
                j = p[j];
            }
            if(str[j+1]==str[i]) p[i] = j+1;
            else p[i] = -1;
        }

        ans = str.substr(0, idx);
        while(k>=idx){
            cout << ans;
            k -= idx;
        }
        if(k) cout << ans.substr(0, k);
        cout << endl;
    }
}
#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;
const int inf = 1001001001;

int n,k,a[1111111];
string s, names[1111111], ans[1111111];
int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);

    cin >> n >> k;
    for (int i=0; i<n; i++){
        names[i]=(char)'A'+i;
        if (names[i]>"Z"){
            names[i]="Ab";
            names[i]+=(char)'a'+i-26;
        }
        //cout << names[i] << endl;
    }
    int poz=0;
    cin >> s;
    if (s=="NO"){
        cout << names[poz] << ' ' << names[poz] << ' ';
        ans[0]=names[poz];
        ans[1]=names[poz];
        poz++;
        for (int j=2; j<k; j++){
            cout << names[poz] << ' ';
            ans[j]=names[poz];
            poz++;
        }
    }
    else{
        for (int j=0; j<k; j++){
            cout << names[poz] << ' ';
            ans[j]=names[poz];
            poz++;
        }
    }
    for (int i=k; i<n; i++){
        cin >> s;
        if (s=="NO"){
            cout << ans[i-k+1] << ' ';
            ans[i]=ans[i-k+1];
        }
        else{
            cout << names[poz] << ' ';
            ans[i]=names[poz];
            poz++;
        }
    }

    return 0;
}
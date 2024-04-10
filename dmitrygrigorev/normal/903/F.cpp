#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int> > sost, pr;
int ans[1000][256];
int n;
vector<int> P;
char matrix[4][1000];
vector<int> refr(vector<int> now){
    vector<int> ans;
    for (int i=0; i < now.size(); i++){
        for (int j=0; j < now[i] + (now[i] == 0); j++){
            ans.push_back(now[i]);
        }
    }
    return ans;
}
void get(int ost, vector<int> &help){
    if (ost == 0){
        sost.push_back(refr(help));
        vector<int> chelp = help;
        sort(chelp.begin(), chelp.end());
        pr.push_back(chelp);
    }
    else{
        for (int i=0; i <= ost; i++){
            help.push_back(i);
            get(ost - i - (i==0), help);
            help.pop_back();
        }
    }
}
int recursion(int r, int A, int B, int C, int D){
    if (r == n) return 0;
    int code = A + 4*B + 16*C + 64*D;
    if (ans[r][code] != -1) return ans[r][code];
    int MX = min((int) 4, n-r);
    int res = 1e9;
    for (int i=0; i < pr.size(); i++){
        if (pr[i].back() > MX) continue;
        if (matrix[0][r] == '*' && A == 0 && sost[i][0] == 0) continue;
        if (matrix[1][r] == '*' && B == 0 && sost[i][1] == 0) continue;
        if (matrix[2][r] == '*' && C == 0 && sost[i][2] == 0) continue;
        if (matrix[3][r] == '*' && D == 0 && sost[i][3] == 0) continue;
        int price = 0;
        for (int j=0; j < pr[i].size(); j++) price += P[pr[i][j]];
        int AA = max(A-1, sost[i][0]-1);
        int BB = max(B-1, sost[i][1]-1);
        int CC = max(C-1, sost[i][2]-1);
        int DD = max(D-1, sost[i][3]-1);
        int Z = 0;
        AA = max(AA, Z);
        BB = max(BB, Z);
        CC = max(CC, Z);
        DD = max(DD, Z);
        res = min(res, price + recursion(r+1, AA, BB, CC, DD));
    }
    ans[r][code] = res;
    return res;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> help;
    get(4, help);
    vector<int> V;
    V.push_back(2);
    V.push_back(3);
    pr.push_back(V);
    pr.push_back(V);
    vector<int> VV;
    VV.push_back(3);
    VV.push_back(3);
    VV.push_back(3);
    VV.push_back(2);
    sost.push_back(VV);
    sort(VV.begin(), VV.end());
    sost.push_back(VV);
    vector<int> S;
    S.push_back(3);
    S.push_back(3);
    pr.push_back(S);
    vector<int> SS;
    SS.push_back(3);
    SS.push_back(3);
    SS.push_back(3);
    SS.push_back(3);
    sost.push_back(SS);
    S.clear();
    S.push_back(2);
    S.push_back(2);
    pr.push_back(S);
    pr.push_back(S);
    SS.clear();
    SS.push_back(2);
    SS.push_back(2);
    SS.push_back(2);
    SS.push_back(0);
    sost.push_back(SS);
    SS.clear();
    SS.push_back(0);
    SS.push_back(2);
    SS.push_back(2);
    SS.push_back(2);
    sost.push_back(SS);
    S.push_back(1);
    pr.push_back(S);
    pr.push_back(S);
    SS.clear();
    SS.push_back(2);
    SS.push_back(2);
    SS.push_back(2);
    SS.push_back(1);
    sost.push_back(SS);
    SS.clear();
    SS.push_back(1);
    SS.push_back(2);
    SS.push_back(2);
    SS.push_back(2);
    sost.push_back(SS);
    SS.clear();
    cin >> n;
    P.push_back(0);
    for (int i=0; i < 4; i++){
        int X;
        cin >> X;
        P.push_back(X);
    }
    for (int i=0; i<n; i++){
        for (int j=0; j < 256; j++){
            ans[i][j] = -1;
        }
    }
    for (int i=0; i < 4; i++){
        for (int j=0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    recursion(0, 0, 0, 0, 0);
    cout << ans[0][0] << endl;
    return 0;
}
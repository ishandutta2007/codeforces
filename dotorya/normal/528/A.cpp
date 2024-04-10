#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> cutted[2];
vector <long long> ANS;
int rev_chk[2][200050];
int d[200050][2]; // [0] : chk, [1] : pos
int left[2][200050];
int right[2][200050];
long long length[2][200050];
long long length_sum[2][200050];
int main() {
    long long W, H, mx[2] = {0,0}, t_long;
    int N, t, t1, t2, t3, i;
    char c[2];
    scanf("%I64d %I64d %d", &W, &H, &N);
    for(i = 1; i <= N; i++) {
        scanf("%s %d", c, &d[i][1]);
        if(c[0] == 'H') d[i][0] = 0;
        else d[i][0] = 1;
        cutted[d[i][0]].push_back(d[i][1]);
    }
    sort(cutted[0].begin(), cutted[0].end());
    sort(cutted[1].begin(), cutted[1].end());
    for(i = 0; i < cutted[0].size(); i++) {
        rev_chk[0][cutted[0][i]] = i+1;
        if(i == 0) length[0][1] = cutted[0][0];
        else length[0][i+1] = cutted[0][i] - cutted[0][i-1];
        if(mx[0] < length[0][i+1]) mx[0] = length[0][i+1];
        left[0][i+1] = right[0][i+1] = i+1;
        length_sum[0][i+1] = length_sum[0][i]+length[0][i+1];
    }
    if(cutted[0].size() != 0) {
        length[0][cutted[0].size()+1] = H-cutted[0][cutted[0].size()-1];
        if(mx[0] < length[0][cutted[0].size()+1]) mx[0] = length[0][cutted[0].size()+1];
        left[0][cutted[0].size()+1] = right[0][cutted[0].size()+1] = cutted[0].size()+1;
        length_sum[0][cutted[0].size()+1] = length_sum[0][cutted[0].size()]+length[0][cutted[0].size()+1];
    }
    else mx[0] = H;
    for(i = 0; i < cutted[1].size(); i++) {
        rev_chk[1][cutted[1][i]] = i+1;
        if(i == 0) length[1][1] = cutted[1][0];
        else length[1][i+1] = cutted[1][i] - cutted[1][i-1];
        if(mx[1] < length[1][i+1]) mx[1] = length[1][i+1];
        left[1][i+1] = right[1][i+1] = i+1;
        length_sum[1][i+1] = length_sum[1][i]+length[1][i+1];
    }
    if(cutted[1].size() != 0) {
        length[1][cutted[1].size()+1] = W-cutted[1][cutted[1].size()-1];
        if(mx[1] < length[1][cutted[1].size()+1]) mx[1] = length[1][cutted[1].size()+1];
        left[1][cutted[1].size()+1] = right[1][cutted[1].size()+1] = cutted[1].size()+1;
        length_sum[1][cutted[1].size()+1] = length_sum[1][cutted[1].size()]+length[1][cutted[1].size()+1];
    }
    else mx[1] = W;
    for(i = N; i >= 1; i--) {
        ANS.push_back(mx[0]*mx[1]);
        t = d[i][0];
        t1 = rev_chk[t][d[i][1]];
        t2 = left[t][t1];
        t3 = right[t][t1+1];
        right[t][t2] = t3;
        left[t][t3] = t2;
        if(length_sum[t][t3] - length_sum[t][t2-1] > mx[t]) mx[t] = length_sum[t][t3]-length_sum[t][t2-1];
    }
    while(!ANS.empty()) {
        printf("%I64d\n", ANS.back());
        ANS.pop_back();
    }
    return 0;
}
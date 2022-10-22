#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

int n;
int nums[32][440000];
int ans[32];


int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
        scanf("%d", &nums[31][i]);
        for(int j = 0;j < 31;j++){
            nums[j][i] = nums[31][i] & ((1<<j)-1);
            int b = (nums[31][i] >> j) % 2;
            b = b * (n-1) % 2;
            ans[j] ^= b;
        }
    }
    for(int i = 1;i < 31;i++){
        sort(nums[i], nums[i] + n);
        int l = n-1;
        int cnt = 0;
        for(int r = 0;r < n;r++){
//            cout << nums[i][r] << " ";
            if(nums[i][r] * 2 >= (1 << i))cnt--;
            while(l >= 0 && nums[i][l] + nums[i][r] >= (1 << i))l--;
            cnt += n-l-1;
        }//cout << endl;
        cnt /= 2;
        if(cnt % 2)ans[i]^=1;
//        cout << i << " " << ans[i] << " cnt:" << cnt << endl;
    }
    int ans_num = 0;
    for(int i = 31;i >= 0;i--){
        ans_num*=2;
        ans_num += ans[i];
    }
    cout<< ans_num << endl;
    return 0;
}
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

#define MOD 998244353
typedef long long Int;

Int ans[1100000];
int main(){
ans[1] = 1;
ans[2] = 1;
ans[4]=1;
ans[5]=1;
ans[9]=1;
ans[10]=1;
ans[20]=1;
ans[21]=1;
ans[41]=1;
ans[42]=1;
ans[84]=1;
ans[85]=1;
ans[169]=1;
ans[170]=1;
ans[340]=1;
ans[341]=1;
ans[681]=1;
ans[682]=1;
ans[1364]=1;
ans[1365]=1;
ans[2729]=1;
ans[2730]=1;
ans[5460]=1;
ans[5461]=1;
ans[10921]=1;
ans[10922]=1;
ans[21844]=1;
ans[21845]=1;
ans[43689]=1;
ans[43690]=1;
ans[87380]=1;
ans[87381]=1;
ans[174761]=1;
ans[174762]=1;
ans[349524]=1;
ans[349525]=1;
ans[699049]=1;
ans[699050]=1;

    Int n;
    cin >> n;
    cout << ans[n] << endl;
    return 0;
}
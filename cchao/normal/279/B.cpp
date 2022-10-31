#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;
queue<int> q;
int main(){
    int n, t, tmp, sum=0, ans = 0;
    scanf("%d%d", &n, &t);
    for(int i = 0; i < n; ++i){
        scanf("%d", &tmp);
        q.push(tmp); sum += tmp;
        while(sum > t && q.size()){
            sum -= q.front();
            q.pop();
        }
        ans = max(ans, (int)q.size());
    }
    cout << ans << endl;
    return 0;
}
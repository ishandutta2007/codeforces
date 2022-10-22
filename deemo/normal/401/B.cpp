#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<utility>
#include<iomanip>

using namespace std;

int x , k , type , a , b , arr[4005] , ans , ans1;

int main(){
    cin >> x >> k;
    for (int i = 0 ; i < k ; i++){
	 cin >> type;
	 if (type == 2){
	     cin >> a;   
	     arr[a] = 1;
	     continue;
	 }

	 if (type == 1){
	     cin >> a >> b;
	     arr[a] = 1;
	     arr[b] = 1;
	     continue;
	 }
    }

    int i = 1;
    while (i < x){
	 while (arr[i] == 1)	i++;
	 if (i >= x) break;

	 int temp = i;
	 while (arr[i] == 0 && i < x)	i++;
	 ans += ceil((i - temp) / double(2));
	 ans1 += i - temp;
    }
    cout << ans << " " << ans1 << endl;

    return 0;
}
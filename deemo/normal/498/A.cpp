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

int x_1 , x_2 , y_1 , y_2 , m ,a , b , c , ans;

long long get(int f , int g){
    long long temp1 , temp2;
    temp1 = a;  
    temp1 *= f;
    temp2 = b;
    temp2 *= g;
    
    return  temp1 + temp2 + c;
}

int main(){
    cin >> x_1 >> y_1;	   
    cin >> x_2 >> y_2;
    
    cin >> m;
    for (int i = 0 ; i < m ; i++){
	 cin >> a >> b >> c;
	 long long temp1 = get(x_1 , y_1) , temp2 = get(x_2 , y_2);
	 if ((temp1 > 0) != (temp2 > 0)) ans++;
    }
    cout << ans << endl;
    return 0;
}
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

long long int r , g , b;
vector<long long>   arr;

int main(){
    int temp;
    for (int i = 0 ; i < 3 ; i++){
	 cin >> temp;
	 arr.push_back(temp);
    }	 
    sort(arr.begin() , arr.end());
    reverse(arr.begin() , arr.end());

    if (arr[0] == arr[2]){//ok
	 cout << arr[0] << endl;
	 return  0;
    }    
    
    if (arr[0] == arr[1]){//ok
	 int c = (arr[1] - arr[2]) * 2;
	 int ans = c / 3;
	 cout << ans + arr[2] << endl;
	 return  0;
    }

    if (arr[1] == arr[2]){//faghat avvali bishtar az baghias
	 int c = arr[0] - arr[1];//har 2 harekat, 4 ta az avvali yeki az un 2ta kam mikoneh
	 long long int ans = (long long)(min(int(arr[2]) , (c / 3)) * 2);
	 arr[2] -= min((c / 3) , int(arr[2]));
	 cout << ans + arr[2] << endl;
	 return  0;
    }

    //hameh namosavi
    int c = arr[0] - arr[1];
    int d = arr[0] - arr[2];
    int e = arr[1] - arr[2];
    if (e > c){
	 int ans = c;//avvali ba dovvomi mosavi
	 arr[0] -= 2 * c;	arr[1] -= c;
	 d = 2 * (arr[0] - arr[2]);    
	 ans += (d / 3);
	 cout << ans + arr[2] << endl;
	 return 0;
    }

    //faselehe a ba b kamtar az b ba c
    int ans = e;
    arr[0] -= 2 * e;
    arr[1] -= e;
    e = (arr[0] - arr[1]);
    ans += (long long)(min(int(arr[2]) , (e / 3)) * 2);
    arr[2] -= min(int(arr[2]) , e / 3);
    cout << ans + arr[2] << endl;
    return 0;
}
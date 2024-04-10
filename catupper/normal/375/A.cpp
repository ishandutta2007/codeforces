#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    string str, ans = "";
    cin >> str;
    bool cnt1 = false, cnt6 = false, cnt8 = false, cnt9 = false;
    int p = 0;
    for(int i = 0;i < str.size();i++){
	if(!cnt1 && str[i] == '1'){
	    cnt1 = true;continue;
	}
	if(!cnt6 && str[i] == '6'){
	    cnt6 = true;continue;
	}
	if(!cnt8 && str[i] == '8'){
	    cnt8 = true;continue;
	}
	if(!cnt9 && str[i] == '9'){
	    cnt9 = true;continue;
	}
	ans += str[i];
	p *= 10;
	p += (str[i] - '0');
	p %= 7;
    }
    int x = 1;
    for(int i = 0;i < ans.size();i++){
	x *= 10;
	x %= 7;
    }
    int nums[] = {1, 6, 8, 9};
    do{
	int n = nums[0] * 1000 + nums[1] * 100 + nums[2] * 10 + nums[3];;
	if((p + n * x) % 7 == 0){
	    break;
	}
    }while(next_permutation(nums, nums + 4));
    cout << nums[0] << nums[1] << nums[2] << nums[3] << ans << endl;
    return 0;
}
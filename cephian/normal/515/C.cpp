#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    
    int n;
    string str;
    cin >> n>>str;
    int nums[10];
    fill(nums, nums+10, 0);
    for(int i = 0; i < str.size(); ++i) {
        for(int j = '2';  j <= str[i]; ++j)
            ++nums[j-'0'];
    }
    
    while(nums[4]) {
        --nums[4];
        nums[2] += 2;
    }
    while(nums[6]) {
        --nums[6];
        ++nums[2];
        ++nums[3];
    }
    while(nums[8]) {
        --nums[8];
        nums[2] += 3;
    }
    while(nums[9]) {
        --nums[9];
        nums[3] += 2;
    }
    
    while(nums[7]) {
        cout << '7';
        --nums[7];
        --nums[5];
        nums[3] -= 2;
        nums[2] -= 4;
    }
    while(nums[5]) {
        cout << '5';
        --nums[5];
        nums[3]--;
        nums[2]-=3;
    }
    while(nums[3]) {
        cout << '3';
        --nums[3];
        --nums[2];
    }
    while(nums[2]) {
        cout << '2';
        --nums[2];
    }
    cout << "\n";
    
    return 0;
}
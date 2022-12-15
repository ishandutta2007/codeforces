

    #include<bits/stdc++.h>
    using namespace std;
     
    int main(){
        int k;
        cin >> k;
        int i = 1;
        while(1){
            int t = i, s = 0;
            while(t > 0)
                s += t % 10, t /= 10;
            if (s == 10) k--;
            if (k == 0){
                cout << i << endl;
                return 0;
            }
            i ++;
        }
    }
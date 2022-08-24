#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;
    vector<double>data;
    vector <double> data1;
    vector<double> help;
    bool marker;

vector<string> res(int plus){
    double maximum = 0;
    int ind;
    int last;
    bool good = false;
    for (int i=0;i<help.size();i++){
        if (i > 0){
            if (help[i - 1] != help[i]){
                good = true;
            }
        }
        if (help[i] > maximum){
            ind = i;
            maximum = help[i];
        }
        }
    vector<string> answer;
    if (good == false){
        marker = true;
        return answer;
    }
    else{
        if (ind > 0){
            int l = help.size();
            while (ind > 0){
                string a;
                stringstream ost;
                ost << ind + plus;
            a += ost.str();
            a += " ";
            a += "L";
            answer.push_back(a);
            l -= 1;
            ind -= 1;
            }
            while (l > 1){
                string a;
            stringstream ost;
                ost << plus;
            a += ost.str();
            a += " ";
            a += "R";
            answer.push_back(a);
            l -= 1;
            }
        }
        else{
            for (int i=1;i<help.size();i++){
                if (help[i] != maximum & help[i-1] == maximum){
                    last = i - 1;
                }
            }
            int l = help.size();
            while (last != l - 1){
                string a;
                stringstream ost;
                ost << last + plus;
            a += ost.str();
            a += " ";
            a += "R";
            answer.push_back(a);
            l -= 1;
            }
            while (l > 1){
                string a;
            stringstream ost;
                ost << l - 1 + plus;
            a += ost.str();
            a += " ";
            a += "L";
            answer.push_back(a);
            l -= 1;
            }
        }
    return answer;
}
}
int main()
{
    int n;
    marker = false;
    cin >> n;
    double m;
    for (int i=0; i<n;i++){
        cin >> m;
        data.push_back(m);
    }
    int q;
    cin >> q;
    for (int i=0; i<q;i++){
            cin >> m;
    data1.push_back(m);
    }
    int u1 = 0;
    int u2 = 0;
    double now = data1[u2];
    vector<string> answer;
    double sum = 0;
          int  counter = 1;
    while (u1 < n){
        help.push_back(data[u1]);
        if (data[u1] == data1[u2]){
                if (sum > 0){
                    u1 = n;
                    marker = true;
                    continue;
                }
                else{
                    u1++;
                    u2++;
                    counter ++;
                    sum = 0;
                    now = data1[u2];
                    help.clear();
                    continue;
                }
        }
        sum += data[u1];
        if (sum == now){
            vector<string> result = res(counter);
            if (marker == false){
            for (int i=0; i<result.size();i++){
                answer.push_back(result[i]);
            }
            }
            else{
                u1 = n;
            }
            counter += 1;
            u1 += 1;
            u2 += 1;
            sum = 0;
            now = data1[u2];
            help.clear();
        }
        else{
            if (sum > now){
                u1 = n;
                marker = true;
            }

        else{
            u1 += 1;
        }
        }
    }
    if (marker == false & u2 == data1.size()){
            cout << "YES" << endl;;
        for (int i=0; i<answer.size();i++){
            cout << answer[i] << endl;
        }
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}
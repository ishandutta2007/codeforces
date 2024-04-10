#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include <bitset>
#include <time.h>
#define int long long
using namespace std;
struct Line{double kx; double b; double x1; double x2;};
double CONST = pow(10, 12);
int n, k, ai;
double bi;
vector<double> pre, summ, resumm;
vector<double> data;
double intersec(Line f, Line s){
    return (s.b - f.b) / (f.kx - s.kx);
}
int bs(double number, vector<Line> &v){
    int l = 0;
    int r = v.size();
    while (r - l > 1){
        int m = (l + r) / 2;
        if (v[m].x1 <= number) l = m;
        else r = m;
    }
    return l;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    double s1 = 0, s2 = 0, s3 = 0;
    for (int i=0;i<n;i++){
        cin >> ai;
        bi = ai;
        s1 += bi;
        s2 += s1 / bi;
        s3 += 1 / bi;
        data.push_back(bi);
        pre.push_back(s2);
        summ.push_back(s1);
        resumm.push_back(s3);
    }
    vector<double> answers;
    for (int i=0;i<n;i++){
        answers.push_back(pre[i]);
    }
    for (int p=1;p<k;p++){
        vector<Line> st;
        vector<double> na;
        for (int i=0;i<answers.size()-1;i++){
            Line ll;
            ll.kx = - summ[i+p-1];
            ll.b = summ[i+p-1] * resumm[i+p-1] + answers[i] - pre[i+p-1];
            while (st.size() > 0){
                double t = intersec(ll, st.back());
                if (t <= st.back().x1){
                    st.pop_back();
                }
                else{
                    st.back().x2 = t;
                    break;
                }
            }
            ll.x2 = CONST;
            if (st.size() == 0) ll.x1 = 0;
            else ll.x1 = st.back().x2;
            st.push_back(ll);
            int ind = bs(resumm[i + p], st);
            double an = pre[i + p] + st[ind].kx * resumm[i + p] + st[ind].b;
            na.push_back(an);
        }
        answers = na;
    }
    cout.precision(30);
    cout << answers.back() << endl;
    return 0;
}
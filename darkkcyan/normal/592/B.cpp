#include <iostream>

using namespace std;

// input
long long int n;

// output;
long long int result;

// functions
void readInput(istream& is) {
    is >> n;
}

void writeOutput(ostream& os) {
    os << result << endl;
}

void process() {
    // just the sum of 3, 5, 7, ...
    long long int t = (n - 3) * 2 + 1;
    result = (t + 1) * ((t - 1) / 2 + 1) / 2;
}

int main(void) {
    readInput(cin);
    process();
    writeOutput(cout);

    return 0;
}
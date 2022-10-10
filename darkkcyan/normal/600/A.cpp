#include <iostream>
#include <queue>

using namespace std;

bool isInAWord(string& str, int index) {
    return (
        index >= 0 and index < str.size() and
        str[index] != ',' and str[index] != ';'
    );
}

int skipToNextWord(string& str, int index) {
    while (isInAWord(str, index)) {
        ++index;
    }
    ++index;
    return index;
}

void printNum(string& str, int index) {
    while (isInAWord(str, index)) {
        cout << str[index];
        ++index;
    }
}

void printQueue(string& str, queue<int>& que) {
    if (que.empty()) {
        cout << "-\n";
        return;
    }

    cout << '"';
    while (!que.empty()) {
        int ind = que.front();
        que.pop();
        printNum(str, ind);
        if (!que.empty()) cout << ',';
    }
    cout << "\"\n";
}

bool isNum(string& str, int index) {
    if (str[index] == '0' and isInAWord(str, index + 1)) {
        return false;
    }
    while (isInAWord(str, index)) {
        if (str[index] < '0' or str[index] > '9') return false;
        ++index;
    }
    return true;
}

int main (void) {
	ios_base::sync_with_stdio(0);
	string inp;

	getline(cin, inp);
	queue <int> num;
	queue <int> nonNum;

    if (inp[inp.size() - 1] == ',' or inp[inp.size() - 1] == ';')
        inp += ',';

    int i = 0;
    while (i < inp.size()) {
        // empty string
        if (!isInAWord(inp, i)) {
            // cerr << "non num: " << i << '\n';
            nonNum.push(i);
        } else if (isNum(inp, i)) {
            // cerr << "num: " << i << '\n';
            num.push(i);
        } else {
            // cerr << "non num: " << i << '\n';
            nonNum.push(i);
        }

        i = skipToNextWord(inp, i);
    }

    printQueue(inp, num);
    printQueue(inp, nonNum);

	return 0;
}
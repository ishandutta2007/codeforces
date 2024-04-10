"use strict"
if (typeof print === 'undefined') var print = console.log;
if (typeof readline == 'undefined') {
    let id = 0, lines = require('fs').readFileSync('/dev/stdin').toString().split('\n');
    var readline = () => lines[id ++];
}

let nums = () => readline().split(' ').map(x => +x);

let t = nums(), n = t[0], m = t[1];
let a = nums(), b = [...a];

function findmin() {
    let ans = 0;
    b.sort((a, b) => a - b);
    for (let i = -1; ++i < n; ) {
        while (b.length && b[0] == 0) b.shift();
        if (!b.length) break;
        ans += b[0]--;
    }
    return ans;
}

function findmax() {
    let ans = 0;
    for (let i = -1; ++i < n; ) {
        let t = 0;
        for (let f = 0; ++f < m; )
            if (a[t] < a[f]) t = f;
        if (a[t] == 0) break;
        ans += a[t]--;
    }
    return ans;
}

print(findmax() + ' ' + findmin());
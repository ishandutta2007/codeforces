"use strict";
if (typeof readline == 'undefined') {
    let id = 0, lines = require('fs').readFileSync('/dev/stdin').toString().split('\n');
    var readline = () => lines[id++];
    var print = console.log;
}
let nums = () => readline().split(' ').map(x => +x);
let t = nums(), n = t[0], l = --t[1], r = --t[2];
let a = nums();
let b = nums();

let c = Array(n).fill(0);
let ans = true;
for (let i = l; i <= r; ++i) {
    ++c[a[i] - 1];
    --c[b[i] - 1];
}
for (let i = 0; i < l && ans; ++i) {
    if (a[i] !== b[i]) 
        ans = false;
}
for (let i = r + 1; i < n && ans; ++i) {
    if (a[i] != b[i])
        ans = false;
}

if (ans) ans = c.every(x => x === 0);

if (ans) print("TRUTH");
else print("LIE");
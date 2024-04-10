const process = require('process');
 
let inp = "";
process.stdin.on('data', chunk => inp += chunk);
process.stdin.on('end', () => {
    inp = inp.split('\n');
    let [n, p] = inp[0].split(' ').map(x => +x);
    let a = inp[1].split(' ').map(x => +x);

    let cnt = [];
    for (let i = 0; i < 2020; ++i) {
        cnt.push(0);
    }

    for (let i of a) cnt[i] ++;

    for (let i = 1; i < 2020; ++i) cnt[i] += cnt[i - 1];

    let ans = [];
    for (let x = 0; x < 3000; ++x) {
        let ok = true;
        for (let i = 0; i < n; ++i) {
            // console.log(i, cnt[x + i], cnt[x + i] - i); 
            let cur_cnt = x + i >= cnt.length ? cnt[2019] : cnt[x + i];
            if (cur_cnt - i < 1 || (cur_cnt - i) % p == 0) {
                ok = false;
                break;
            }
        }
        if (ok) ans.push(x);
    }
    console.log(ans.length);
    console.log(ans.join(' '));
});
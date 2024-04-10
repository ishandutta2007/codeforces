let inputs = []

function read() {
    return inputs.pop();
}

function readInt() {
    return parseInt(read());
}

function solve() {
    ar = []
    for (let i = 1; i < 1e4; i++) {
        if (i % 3 != 0 && i % 10 != 3) {
            ar.push(i);
        }
    }
    let test = readInt();
    while (test--) {
        let k = readInt();
        console.log(ar[k - 1]);
    }
}

function main() {
    inputs = inputString.replace(' ', '\n').trim().split('\n').map((string) => string.trim());
    inputs.reverse(); 
    solve();
}

let inputString = '';

process.stdin.on('data', (inputStdin) => { inputString += inputStdin; });

process.stdin.on('end', (_) => { main(); });
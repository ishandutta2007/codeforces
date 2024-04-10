namespace Solution {
    open Microsoft.Quantum.MachineLearning;
    operation Solve() : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
        return ((1, [2.1566756826189697, 0.0, 2.0, -3.0, 0.0, 0.0]), [ControlledRotation((2, [1]), PauliY, 0), ControlledRotation((1, [2]), PauliY, 1), ControlledRotation((2, [1]), PauliY, 0)], ([1.5707963267948966, 3.141592653589793], 0.0));
    }
}
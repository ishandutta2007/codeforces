namespace Solution {
    open Microsoft.Quantum.MachineLearning;
    operation Solve() : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
        return ((1, [0.0, 0.25]), [ControlledRotation((0, new Int[0]), PauliY, 0), ControlledRotation((1, [0]), PauliY, 0), ControlledRotation((0, new Int[0]), PauliY, 0)], ([3.141592653589793], 0.0));
    }
}